#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"

class TopicSubscribe01 : public rclcpp::Node
{
public:
    // 构造函数,有一个参数为节点名称
    TopicSubscribe01(std::string name) : Node(name), counter(0)
    {
        RCLCPP_INFO(this->get_logger(), "节点%s已启动.", name.c_str());
        simulink_imu_subscribe_ = this->create_subscription<sensor_msgs::msg::Imu>("simulink_imu", 10, std::bind(&TopicSubscribe01::simulink_imu_callback, this, std::placeholders::_1));
    }

private:
     // 声明一个订阅者
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr simulink_imu_subscribe_;
     // 收到话题数据的回调函数
    void simulink_imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
        counter++;
        RCLCPP_INFO(this->get_logger(), "收到%i帧数据,%s",counter,msg->header.frame_id.c_str());
    }
    int counter; //受到指令次数
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<TopicSubscribe01>("ImuCounter_01");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}