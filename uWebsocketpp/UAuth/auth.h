#include <cstdlib>
#include <string>

#include <curl/curl.h>

namespace curl {
    void Authenticate(std::string header, CURL * curl) {
        if (curl) {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, header);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);
            res = curl_easy_perform(curl);
            /** Note that Verification for hosting is provided for the peer, so when you are connecting,
             *  you must be wary that your connection is susceptible to hackers and sniffers.
             *  This hosting plugin will also require that you leave your network BIOS port open for all networks,
             *  Which can lead to remote execution attacks from anyone inside the network.
            **/
        }
    }
    void Cleanup(CURL * curl) {
            curl_easy_cleanup(curl);
    }
}