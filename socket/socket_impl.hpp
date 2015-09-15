#ifndef COMMON_SOCKET_IMPL_HPP
#define COMMON_SOCKET_IMPL_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

/**
 * commlib namespace
 */
namespace commlib
{

/**
 * socket implementation class
 */
class socket_impl
{
public:
    /**
     * Type definition for address length
     */
    typedef socklen_t addr_len;

    /**
     * Create an internal sockaddr_in address
     *
     * @param address target address
     * @param port    target port
     *
     * @return sockaddr_in ready to be used by socket functions
     */
    static sockaddr_in create_address(Uint32 address, unsinged short port);

    /**
     * Return the value of the invalid socket
     *
     * @return socket_handle special invalid value of the invalid socket
     */
    static socket_handle invalid_socket();

    /**
     * Close and destroy a socket
     *
     * @param sock handle of the socket to close
     */
    static void close(socket_handle sock);

    /**
     * Set a socket as blocking or non-blocking
     *
     * @param sock  handle of the socket to set
     * @param block blocking state of the socket
     */
    static void setBlocking(socket_handle sock, bool block);

    /**
     * Get the last socket error status
     *
     * @return Status corresponding to the last socket error
     */
    static Socket::Status getErrorStatus();
};

} // namespace comlib


#endif
