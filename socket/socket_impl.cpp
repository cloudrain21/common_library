#include <socket_impl.hpp>
#include <errno.h>
#include <fcntl.h>
#include <cstring>

namespace commlib
{

sockaddr_in socket_impl::create_address(Uint32 address, unsigned short port)
{
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_add.s_addr = htonl(address);
    addr.sin_family     = AF_INET;
    addr.sin_port       = htons(port);

    return addr;
}

} // namespace commlib
