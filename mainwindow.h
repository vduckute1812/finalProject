#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>
#include "segmentation.h"
#include "camerasubtractor.h"
#include "QMessageBox"
#include "QImage"
#include "QTimer"
#include "vector"
#include "findlinkpixel.h"
#include <opencv2/calib3d.hpp>

using namespace cv;


namespace Ui {
class MainWindow;
}

    

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoCapture firstcapWebcam, secondcapWebcam;
    Mat imgCam1, imgCam2;
    QTimer* tmrTimer;
    int widthFirstScene, heightFirstScene;
    int widthSecondScene, heightSecondScene;
    int widthThirdScene, heightThirdScene;
    vector<cv::Point2f> corners;
    vector<vector<point>> Result;
    vector<point> maxClus;
    int maxIndex;
    Mat imgProc;
    bool foundedCorner;
    cv::Mat sum, sqsum;
    int frame_count;
    Mat dst, resultImg;
    bool first_frame;
    bool show_subtract;
    void sleep(qint64 msec);
    void trainSubtract(Mat& img);
    void getSubtract( Mat& img, Mat &dest);

public slots:
    void processFrameAndUpdateGUI();
    void on_getObject_clicked();

private slots:
    void on_pushButton_clicked();
};



#endif // MAINWINDOW_H
