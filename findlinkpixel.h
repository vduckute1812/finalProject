#ifndef FINDLINKPIXEL_H
#define FINDLINKPIXEL_H


#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


typedef struct
{
    int x, y;
}point;

vector<point> findCheckPoints(vector<point> rows, int colsLength);
vector<vector<point>> getPoint(const Mat& img, int inRow);
bool checkRow(const vector<point> &rowCheck, const vector<point> &rowCluster);
vector<point> getRow(const vector<point>& rows, int index);
vector<point> mergeValue(const vector<point>& mat1, const vector<point>& mat2, int index);
void removeElement(vector<vector<point>>& matQ, vector<int>& removeArray);
void changeQueue(vector<vector<point>>& matQ, vector<point> checkR, vector<int>& checkRowQueue);
vector<vector<point>> findLinkPixel(const Mat& img);
long countMaxClus(const vector<vector<point>>& img);
void printRow(const vector<point>& row);
void resultFindClus(vector<vector<point>>& Result, vector<point>& maxClus, int maxIndex, Mat& frame, Mat& matResut);

#endif // !findLinkPixel.h
