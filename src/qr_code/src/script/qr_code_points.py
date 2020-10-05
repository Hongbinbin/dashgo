import rospy
import cv2
import pyzbar.pyzbar as pyzbar
import sensor_msgs.point_cloud2 as pc2

from std_msgs.msg import String
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2, PointField
from cv_bridge import CvBridge, CvBridgeError

def callback(Points):
    print type(Points.data)

def qr_code_points_listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('camera_points_info', anonymous=True)

    rospy.Subscriber('/camera/depth/color/points', PointCloud2, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    qr_code_points_listener()

