/*
 *   Copyright (C) 2009-2014,2016,2018,2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	IcomNetwork_H
#define	IcomNetwork_H

#include "RptNetwork.h"
#include "UDPSocket.h"
#include "Timer.h"

#include <cstdint>
#include <string>

class CIcomNetwork : public IRptNetwork {
public:
	CIcomNetwork(unsigned int localPort, bool debug);
	virtual ~CIcomNetwork();

	virtual bool open();

	virtual bool write(const unsigned char* data, unsigned int length, const in_addr& address, unsigned int port);

	virtual bool read(unsigned char* data, in_addr& address, unsigned int& port);

	virtual void close();

    virtual void clock(unsigned int ms);

private:
	CUDPSocket   m_socket;
	in_addr      m_address;
	unsigned int m_port;
	bool         m_debug;
};

#endif
