#include "drive.h"
#include "udp_server.h"
#include "udp_client.h"

namespace uss_source
{
static UDPTestClient udp_test("192.168.1.1", 7501, 7500);

Drive::Drive(std::shared_ptr<runcontex::RunContex> f_runcontex) : SourceBase(f_runcontex)
{
}

int Drive::Init()
{

    udp_test.init();
    return 0;
}
int Drive::Run()
{
    udp_test.run();
    return 0;
}
} // namespace uss_source
