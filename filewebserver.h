#ifndef FILEWEBSERVER_H
#define FILEWEBSERVER_H
#include<configurable.h>
#include<configuration.h>
#include<boost/asio.hpp>
#include<boost/filesystem.hpp>


using namespace boost::asio;
class FileWebServer : public Configurable
{
public:
    FileWebServer(Configuration  &configObj);
    FileWebServer(const FileWebServer &) = delete;
    void run();
private:
    void printDirectoryTree();

private:
    std::string mipAddress;
    int mPort;
    std::string mDocRoot;
    ip::tcp::acceptor *mAcceptor;
    ip::tcp::socket *mSocket;
    std::stringstream mMainText;
    io_service m_io_service;
};

#endif // FILEWEBSERVER_H
