#include "ros/ros.h"
#include "my_service/Determinant.h"
#include "std_msgs/Float32.h"

void receive(const std_msgs::Float32 &input){

	float determ_recieve = input.data;
	
	if (int(determ_recieve) % 2 == 0)
	{
		ROS_INFO("even");
	}
	else
	{
	 	ROS_INFO("odd");
	}


	return;

}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"determ_publisher");

	ros::NodeHandle n;
	my_service::Determinant srv;
	ros::Subscriber sub = n.subscribe("/det_mat", 100, receive);

	ros::spin();



    return 0;
}

