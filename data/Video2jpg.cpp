#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fmt/format.h>
#include <string>
using namespace cv;

std::string ObjectName = "mouse";
std::string pat = fmt::format("./video/{}.mp4",ObjectName);

int main()
{
    VideoCapture video = VideoCapture(pat);

    
    double fps = video.get(CAP_PROP_FPS);
    int width = video.get(CAP_PROP_FRAME_WIDTH);
    int height = video.get(CAP_PROP_FRAME_HEIGHT);

    std::cout<<"FPS"<<fps<<" width"<<width<<" height"<<height<<std::endl;

    Mat frame;
    int num = video.get(CAP_PROP_FRAME_COUNT);
    for(int i = 0;i < num-1;i ++)
    {
        video.read(frame);
        // imshow("test",frame);
        imwrite(fmt::format("./img/{}/{}.jpg",ObjectName,i),frame);

        // if(waitKey(30) == 'q') break;
    }

    video.release(); // 释放对象

    return 0;
}