#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "my_service/Determinant.h"

ros::Publisher publisher;

bool determ(my_service::Determinant::Request &req,
    my_service::Determinant::Response &res)
{
	res.det = req.first*req.fifth*req.ninth+req.seventh*req.second*req.sixth+req.fourth*req.eighth*req.third-req.seventh*req.fifth*req.third-req.first*req.eighth*req.sixth-req.fourth*req.second*req.ninth;
	std_msgs::Float32 determ_msg;
	determ_msg.data=res.det;
		ROS_INFO("request:a11=%d;a12=%d;a13=%d;a21=%d;a22=%d;a23=%d;a31=%d;a32=%d;a33=%d;",req.first,req.second,req.third,req.fourth,req.fifth,req.sixth,req.seventh,req.eighth,req.ninth);
	ROS_INFO("sending back response:[%f]",res.det);
	
	publisher.publish(determ_msg);
	ros::spinOnce();
	
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"determinant_of_matrix_server");
	ros::NodeHandle n;
	ros::ServiceServer service=n.advertiseService("determinant_of_matrix",determ);
	publisher = n.advertise<std_msgs::Float32>("/det_mat", 100);

	ROS_INFO("READY TO FIND DETERMINANT");
	ros::spin();
	return 0;
}
