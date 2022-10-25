#include "ros/ros.h"
#include "my_service/Determinant.h"
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc,argv,"determ_publisher");

    ros::NodeHandle n;
    ros::ServiceClient 	client=n.serviceClient<my_service::Determinant>("determinant_of_matrix");
    my_service::Determinant srv;

    while (ros::ok())
    {
        int a11,a12,a13,a21,a22,a23,a31,a32,a33;
        std::cout<<"input matrix value:";    
        std::cin>>a11;
        std::cin>>a12;
        std::cin>>a13;
        std::cin>>a21;
        std::cin>>a22;
        std::cin>>a23;
        std::cin>>a31;
        std::cin>>a32;
        std::cin>>a33;
       
        
        srv.request.first = a11;
        srv.request.second = a12;
        srv.request.third = a13;
        srv.request.fourth = a21;
        srv.request.fifth = a22;
        srv.request.sixth = a23;
        srv.request.seventh = a31;
        srv.request.eighth = a32;
        srv.request.ninth = a33;


        if (client.call(srv))
        {
		if (int(srv.response.det)%2==0)
		{
			std::cout<<"even"<<std::endl;
		}
		else
		{
		 	std::cout<<"odd"<<std::endl;
		}
        }
        else
        {
        	std::cout<<"Failed to call service determinant_of_matrix"<<std::endl;
        	return 1;
        }
    }

    return 0;
}
