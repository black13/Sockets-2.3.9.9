#include "HttpGetSocket.h"
#include "SocketHandler.h"
#include "Exception.h"
#include "StdoutLog.h"
#include "File.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
		return -1;
	try
	{
		File fil("httpget.out", "w");
		StdoutLog log;
		SocketHandler h(&log);
		HttpGetSocket sock(h, argv[1], "empty.html");
		sock.SetTrafficMonitor(&fil);
		h.Add(&sock);
		while (h.GetCount())
			h.Select();
	}
	catch (const Exception& e)
	{
		std::cerr << e.ToString() << std::endl;
	}
}
