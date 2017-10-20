#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    firstcapWebcam.open(0);
    secondcapWebcam.open(1);
    widthFirstScene = ui->firstCam->size().width();
    heightFirstScene = ui->firstCam->size().height();
    widthSecondScene = ui->secondCam->size().width();
    heightSecondScene = ui->secondCam->size().height();
    widthThirdScene = ui->thirdImg->size().width();
    heightThirdScene = ui->thirdImg->size().height();

    frame_count = 0;
    if(!firstcapWebcam.isOpened() || !secondcapWebcam.isOpened()){
        ui->plainTextEdit->appendPlainText("Cap not accessed sucessfully");
        return;
    }
    tmrTimer = new QTimer(this);
    connect(tmrTimer, SIGNAL(timeout()),this, SLOT(processFrameAndUpdateGUI()));
    first_frame = false;
    show_subtract = false;

    resultImg = Mat::zeros(Size(heightThirdScene, widthThirdScene), CV_8UC1);

    tmrTimer->start(10);


}

void MainWindow::processFrameAndUpdateGUI(){
    firstcapWebcam.read(imgCam1);
    secondcapWebcam.read(imgCam2);
    if(imgCam1.empty() || imgCam2.empty()){
        ui->plainTextEdit->appendPlainText("Cannot read image from Camera");
        return;
    }
    cv::resize(imgCam1, imgCam1, Size(widthFirstScene, heightFirstScene));
    cv::resize(imgCam2, imgCam2, Size(widthSecondScene, heightSecondScene));
    cvtColor(imgCam1, imgCam1, CV_BGR2RGB);
    cvtColor(imgCam2, imgCam2, CV_BGR2RGB);
    // Training
    if(first_frame){
//        if (frame_count==0){
//            dst = cv::Mat(imgCam1.size(), CV_32FC1);
//        }
        if(frame_count>=20){
            first_frame = false;
            ui->plainTextEdit->appendPlainText(QString("Complete training processing"));
        }

        trainSubtract(imgCam1);
    }

    if(show_subtract){
        getSubtract(imgCam1, dst);
    }

    //Finish traning

//    foundedCorner = findChessboardCorners(imgCam2, Size(6,9), corners);
//    ui->plainTextEdit->appendPlainText(QString::number(foundedCorner));
//    drawChessboardCorners(imgCam2, Size(6,9), corners, foundedCorner);
    QImage qimgCam1((uchar*)imgCam1.data, imgCam1.cols, imgCam1.rows, imgCam1.step, QImage::Format_RGB888);
    QImage qimgCam2((uchar*)imgCam2.data, imgCam2.cols, imgCam2.rows, imgCam2.step, QImage::Format_RGB888);
    ui->firstCam->setPixmap(QPixmap::fromImage(qimgCam1));
    ui->secondCam->setPixmap(QPixmap::fromImage(qimgCam2));
}


void MainWindow::sleep(qint64 msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

void MainWindow::trainSubtract(Mat& img){
    trainingImage(img, frame_count);
    frame_count++;

//    if(frame_count >= 50){
//        this->thread()->quit();

//    }

}

void MainWindow::getSubtract( Mat &img, Mat &dest){
    backgroundDiff(img, dest);
    cv::resize(dest, dest, Size(heightThirdScene, widthThirdScene));
    cv::normalize(dest, dest, 0, 255, NORM_MINMAX, CV_8UC1);
    resultFindClus(Result, maxClus, maxIndex, dest, resultImg);
    QImage qimgCam3((uchar*)resultImg.data, resultImg.cols, resultImg.rows, resultImg.step, QImage::Format_Grayscale8);

    ui->thirdImg->setPixmap(QPixmap::fromImage(qimgCam3));
}

void MainWindow::on_getObject_clicked()
{
    QEventLoop loop;
    ui->plainTextEdit->appendPlainText(QString("Already for training"));
    sleep(5000);
//    QTimer::singleShot(0, &loop, SLOT(trainSubtract(imgCam1)));
//    loop.exec();
    first_frame = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    createModelsfromStats();
    if(frame_count==0){
        ui->plainTextEdit->appendPlainText("You haven't trained Data");
    }
    else{
        show_subtract = true;
    }
}
