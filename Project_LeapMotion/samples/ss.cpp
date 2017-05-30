#include "Leap.h" // the leap sdk header
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<stdio.h>
namespace
{
	void LeapVideo()
	{
		Leap::Controller controller;
		controller.setPolicy(Leap::Controller::POLICY_IMAGES);
		
		cv::String const windowName[] = { "0", "1" };
		
		for (int c=0;;c+=1)
		{
			Leap::Frame const frame = controller.frame(0);
			//FILE *fp = fopen("trainingData.txt","w+");
			/*if(c>100){
				//fprintf(fp,"123");
				std::cout << "Frame id: " << frame.id()
            << ", timestamp: " << frame.timestamp()
            << ", hands: " << frame.hands().count()
            << ", extended fingers: " << frame.fingers().extended().count()
            << ", tools: " << frame.tools().count()
            << ", gestures: " << frame.gestures().count() << std::endl;

				return;
			}*/
			Leap::ImageList const & imageList = frame.images();
			uint8_t const imageCount = imageList.count();

			for (uint8_t imageIndex = 0; imageIndex < imageCount; ++imageIndex)
			{	
				Leap::Image const & image = imageList[imageIndex];
				uint32_t const rows = image.height();
				uint32_t const columns = image.width();
				cv::Mat const mat(rows, columns, CV_8UC1);
				uint32_t const imageSize = sizeof(uint8_t) * rows * columns * image.bytesPerPixel();
				memcpy(mat.data, image.data(), imageSize);
  				printf("%d ",image.distortionWidth());
				if(c>100){
					printf("YES");
					cv::imwrite("image.png", mat);
					const float *f =  image.distortion();
					FILE *fp = fopen("Distortion.txt","w");
					fprintf(fp,"x = [ ");
					for(int i=0;i<128*64;i++) fprintf(fp,"%f, ",*(f+i));
					fprintf(fp," ]");
					return;
				}	
				cv::imshow(windowName[imageIndex], mat);
				cv::waitKey(16); // 60 fps poor man's frame limiter
			}
		}
	}
}

int main(int const argc, char const * const * const argv)
{
	LeapVideo();

	return 0;
}
