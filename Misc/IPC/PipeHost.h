#ifndef MISC_PIPE_HOST
#define MISC_PIPE_HOST

#include "Misc/Common/MiscNamespaceDefs.h"

#include "_internal/posix/PosixPipeHost.h"

#include <functional>
#include <string>
#include <thread>

BEGIN_MISC_NAMESPACE

class PipeHost {
    public:

        PipeHost(
            const std::string& path
        );

        ~PipeHost();

        void Listen();
        void StopListening();

        using DataReceivedFn = std::function<void(const std::string&)>;
        void OnDataReceived(DataReceivedFn dataReceivedFunction);

    private:

        std::string Read();

        bool isListening = false;
        DataReceivedFn onDataReceived = nullptr;
        std::thread listeningThread;
        Misc::PosixPipeHost pipe;
};

END_MISC_NAMESPACE

#endif
