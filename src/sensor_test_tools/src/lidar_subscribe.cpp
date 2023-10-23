#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

class TopicSubscribe01 : public rclcpp::Node
{
public:
    // 构造函数,有一个参数为节点名称
    TopicSubscribe01(std::string name) : Node(name), counter(0)
    {
        RCLCPP_INFO(this->get_logger(), "节点%s已启动.", name.c_str());
        simulink_lidar_subscribe_ = this->create_subscription<sensor_msgs::msg::PointCloud2>("simulink_lidar", 10, std::bind(&TopicSubscribe01::simulink_lidar_callback, this, std::placeholders::_1));
    }

private:
     // 声明一个订阅者
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr simulink_lidar_subscribe_;
     // 收到话题数据的回调函数
    void simulink_lidar_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
    {
        counter++;
        RCLCPP_INFO(this->get_logger(), "收到%i帧数据 点云尺寸%ix%i",counter,msg->width,msg->height);
    }
    int counter; //受到指令次数
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<TopicSubscribe01>("LidarCounter_01");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}