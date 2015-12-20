#include "opencv2/opencv.hpp"
#include <opencv2\core\core.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Card
{
public:
	Card(){}
	Card(Mat mat);
	Card(std::string name, Mat mat);
	~Card();

	std::string _name;
	Mat _cardMatrix;
	vector<KeyPoint> _keyPoints;
	Mat _descriptors;
	std::string _suit;
	int _value;
};

Card::Card(Mat mat){

	_name = "Unknown";
	_cardMatrix = mat;

	//Calculade this card's keypoints and descriptors
	SiftFeatureDetector detector(400);
	SiftDescriptorExtractor extractor;

	detector.detect(_cardMatrix, _keyPoints);
	extractor.compute(_cardMatrix, _keyPoints, _descriptors);
}

Card::Card(std::string name, Mat mat)
{
	_name = name;
	_cardMatrix = mat;

	size_t underscore = _name.find_first_of('_');

	_value = atoi(_name.substr(0, underscore).c_str());
	_suit = _name.substr(underscore +1);

	//Calculade this card's keypoints and descriptors
	SiftFeatureDetector detector(400);
	SiftDescriptorExtractor extractor;

	detector.detect(_cardMatrix, _keyPoints);
	extractor.compute(_cardMatrix, _keyPoints, _descriptors);
}

Card::~Card()
{
}