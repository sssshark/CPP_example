#include <gflags/gflags.h>
#include "logger.h"

// DEFINE_string(logger_conf_path, "./conf/logger.conf", "logger配置文件路径");
DEFINE_string(logger_conf_path, "/home/kali/program/CPP_example/lo4cplus_example/conf/logger.conf", "logger配置文件路径");

log4cplus::Logger Logger::warnningLog;
log4cplus::Logger Logger::errorLog;

Logger::Logger(std::string logConfPath) {
    log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(logConfPath));
    warnningLog = log4cplus::Logger::getInstance("warnninglog");
    errorLog = log4cplus::Logger::getInstance("errorlog");
    configureAndWatchThread = std::make_unique<log4cplus::ConfigureAndWatchThread>(logConfPath);
}

void Logger::Init() {
    static Logger log(FLAGS_logger_conf_path);
}