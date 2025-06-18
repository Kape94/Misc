#include "Misc/IPC/PipeHost.h"
#include "Misc/IPC/PipeWriter.h"

#include <iostream>
#include <string>

int main()
{
    const std::string pipePath("myPipe");

    Misc::PipeHost pipe(pipePath);

    Misc::PipeWriter writer(pipePath);
    writer.Write("Hello");

    const std::string message = pipe.Read();
    std::cout << "Read message: " << message << std::endl;
    std::cout << "Message size: " << message.size() << std::endl;

    return 0;
}