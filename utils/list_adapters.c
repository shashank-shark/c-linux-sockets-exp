#include<stdio.h>
#include<ifaddrs.h>
#include<netdb.h>

int main() {

    struct ifaddrs *addressess;

    if (getifaddrs(&addressess) == -1) {
        printf("getifaddrs failed to get list of network adapters\n");
        return -1;
    }

    struct ifaddrs *traverser = addressess;
    while (traverser) {
        int family = traverser -> ifa_addr -> sa_family;
        if (family == AF_INET || family == AF_INET6) {
            printf ("--------------------------------------------------------------------------------\n");
            printf ("Adapter Name : %s\n", traverser -> ifa_name);
            printf("IP Protocol Version : %s\n", (family == AF_INET ? "IPV4" : "IPV6"));
            const int family_size = family == AF_INET ? sizeof (struct sockaddr_in) : sizeof (struct sockaddr_in6);
            char ap[100];
            getnameinfo(traverser -> ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
            printf("AccessPoint Address: %s\n", ap);
        }
        traverser = traverser -> ifa_next;
    }

    freeifaddrs(addressess);
    return 0;
}
