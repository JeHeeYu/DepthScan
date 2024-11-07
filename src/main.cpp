#include <iostream>
#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

int main() {
    try {
        rs2::context context;
        auto list = context.query_devices();

        if (list.size() == 0) {
            std::cout << "No RealSense devices connected." << std::endl;
            return -1;
        }

        for (auto&& dev : list) {
            std::cout << "Device detected: " << dev.get_info(RS2_CAMERA_INFO_NAME) << std::endl;
        }
    } catch (const rs2::error &e) {
        std::cerr << "RealSense error calling " << e.get_failed_function()
                  << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
