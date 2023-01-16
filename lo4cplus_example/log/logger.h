
#pragma once

#include <log4cplus/logger.h>
#include <log4cplus/log4cplus.h>
#include <log4cplus/ndc.h>
#include <log4cplus/configurator.h>


class Logger {
public:
    static void Init();
    static log4cplus::Logger warnningLog;
    static log4cplus::Logger errorLog;

    std::unique_ptr<log4cplus::ConfigureAndWatchThread> configureAndWatchThread;

private:
    Logger(std::string confPath);
    
};

#define LOG(m) LOG4CPLUS_INFO(log4cplus::Logger::getRoot(), "TEST:" << m)
#define WARN(m) LOG4CPLUS_WARN(Logger::warnningLog, "TEST:" << m)
#define ERROR(m) LOG4CPLUS_ERROR(Logger::errorLog, "TEST:" << m)