#ifndef PARCELS_IRZCAM_H
#define PARCELS_IRZCAM_H

#define CAM_START "GET /udpvideo.cgi?sport=44000&cport=44000&cmd=play&ch=1&format=0 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_STOP  "GET /udpvideo.cgi?sport=44000&cport=44000&cmd=stop&ch=1&format=0 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define UDP_TEST  "Тест UDP"
#define CAM_Znorm  "GET /params.cgi?scale1=0 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_Z2x    "GET /params.cgi?scale1=1 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_Z4x    "GET /params.cgi?scale1=3 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_640x480     "GET /params.cgi?resolution1=8 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_800x600     "GET /params.cgi?resolution1=6 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_1024x768    "GET /params.cgi?resolution1=5 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_1280x1024   "GET /params.cgi?resolution1=4 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"
#define CAM_1920x1080   "GET /params.cgi?resolution1=3 HTTP/1.1\r\nConnection: close\r\nHost: 10.0.0.250\r\nAuthorization: Basic cm9vdDowMDAw\r\n"


#endif // PARCELS_IRZCAM_H

