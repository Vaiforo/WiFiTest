#include "bssidreader.h"

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/wireless.h>
#include <cstring>

QString getCurrentBssid(const char *iface)
{
    int sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        return QString();

    struct iwreq req;
    std::memset(&req, 0, sizeof(req));
    std::strncpy(req.ifr_name, iface, IFNAMSIZ);

    QString mac;
    if (::ioctl(sock, SIOCGIWAP, &req) == 0) {
        const unsigned char *a =
            reinterpret_cast<unsigned char *>(req.u.ap_addr.sa_data);
        char buf[18];
        std::snprintf(buf, sizeof(buf),
                      "%02X:%02X:%02X:%02X:%02X:%02X",
                      a[0], a[1], a[2], a[3], a[4], a[5]);
        mac = QString::fromLatin1(buf);
    }
    ::close(sock);
    return mac;
}
