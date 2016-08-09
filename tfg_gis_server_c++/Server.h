#pragma once

#include <unordered_map>
#include <SFML\Network.hpp>
#include "Jzon.h"

#include "Map.h"
#include "ObjectUser.h"
#include "FightStatus.h"

class Server
{
	typedef std::unordered_map<sf::TcpSocket*, std::string> Clients_Sockets;
	typedef std::unordered_map<int, ObjectUser*> UsersInMemory;
	typedef std::unordered_map<int, FightStatus*> Battles;

	Clients_Sockets clients;
	UsersInMemory users;
	Battles battles;
	bool isGame;

	sf::TcpListener listener;
	Jzon::Parser parser;

	sf::Mutex mutex;
	sf::Mutex mutexObjects;

	void handleMessages();
	void broadcast(std::string str, sf::TcpSocket* c);

	std::vector<Map*> maps;

public:
	Server(unsigned short port, bool isGame);
	~Server();
	
	void battleSchedule(void* fs) {
		sf::sleep(sf::seconds(10.f));	// randRange(20, 40)

		// TODO: Lanzo mensaje con fin de combate y tal!!


		//battles.erase(fs->getId_battle());
		//delete(fs);
	}

	void run();
};

