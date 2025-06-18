#include "PosixPipeHost.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>

// ----------------------------------------------------------------------------

USING_MISC_NAMESPACE

// ----------------------------------------------------------------------------

PosixPipeHost::PosixPipeHost(
    const std::string& _path
) : path(_path)
{
    Create();
}

// ----------------------------------------------------------------------------

PosixPipeHost::~PosixPipeHost()
{
    if (fdRead != -1)
    {
        close(fdRead);
    }
    Close();
}

// ----------------------------------------------------------------------------

void PosixPipeHost::Create()
{
    std::cout << "Going to create and open the pipe..." << std::endl;
    if (mkfifo(path.c_str(), 0666) == -1)
    {
        std::cout << "Error while creating the pipe" << std::endl;
    }

    std::cout << "Going to open the pipe for reading..." << std::endl;
    fdRead = open(path.c_str(), O_RDONLY | O_NONBLOCK);
    if (fdRead == -1)
    {
        std::cout << "Error while opening the pipe for reading" << std::endl;
    }
}

// ----------------------------------------------------------------------------

void PosixPipeHost::Close()
{
    const int status = unlink(path.c_str());
}

// ----------------------------------------------------------------------------

std::string PosixPipeHost::Read()
{
    std::cout << "Reading..." << std::endl;

    if (fdRead == -1)
    {
        std::cout << "Going to open the pipe for reading..." << std::endl;
        fdRead = open(path.c_str(), O_RDONLY | O_NONBLOCK);
        if (fdRead == -1)
        {
            std::cout << "Error while opening the pipe for reading" << std::endl;
        }
    }

    char buffer[2048];
    ssize_t bytesRead = read(fdRead, buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
        return std::string();
    }

    return buffer;
}

// ----------------------------------------------------------------------------
