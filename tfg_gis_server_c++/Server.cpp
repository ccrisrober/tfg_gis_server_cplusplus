#include "Server.h"
#include <iostream>
#include "RealObjects.h"

#define MAXBUFF 512
#define MINBUFF 150

Server::Server(unsigned short port, bool isGame) : isGame(isGame)
{
	this->listener.listen(port);
	this->listener.setBlocking(false);

	RealObjects::Instance()->addKey(1, new KeyObject(1, 5 * 64, 5 * 64, "Red"));
	RealObjects::Instance()->addKey(2, new KeyObject(2, 6 * 64, 5 * 64, "Blue"));
	RealObjects::Instance()->addKey(3, new KeyObject(3, 7 * 64, 5 * 64, "Yellow"));
	RealObjects::Instance()->addKey(4, new KeyObject(4, 8 * 64, 5 * 64, "Green"));

	std::map<std::string, KeyObject*> ks0;
	for (int i = 1; i < 5; i++) {
		ks0.insert(std::pair<std::string, KeyObject*>(std::to_string(i), RealObjects::Instance()->getKey(i)));
	}

	Map* m = new Map(1, "1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 5, 5, 7, 5, 5, 5, 5, 1, 1, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 0, 0, 4, 6, 5, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 4, 0, 5, 5, 5, 0, 8, 8, 8, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 4, 0, 0, 0, 1, 1, 0, 5, 5, 5, 0, 0, 0, 8, 8, 8, 4, 0, 1, 1, 0, 1, 0, 0, 0, 0, 4, 0, 0, 1, 1, 1, 1, 4, 0, 0, 0, 1, 0, 5, 0, 4, 4, 0, 0, 8, 8, 8, 1, 4, 1, 4, 0, 1, 0, 0, 0, 0, 4, 4, 0, 1, 1, 1, 1, 1, 1, 4, 0, 1, 0, 5, 0, 4, 4, 4, 0, 8, 8, 8, 1, 1, 1, 1, 0, 1, 0, 0, 4, 4, 4, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 5, 4, 4, 4, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 0, 0, 4, 0, 5, 5, 5, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 4, 0, 5, 5, 5, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 5, 5, 5, 0, 0, 0, 1, 1, 1, 4, 0, 0, 0, 1, 1, 0, 5, 5, 5, 0, 0, 0, 1, 1, 1, 4, 0, 1, 1, 0, 1, 0, 5, 0, 4, 4, 0, 0, 1, 1, 1, 1, 4, 0, 0, 0, 1, 0, 5, 0, 4, 4, 0, 0, 1, 1, 1, 1, 4, 1, 4, 0, 1, 0, 5, 0, 4, 4, 4, 0, 1, 1, 1, 1, 1, 1, 4, 0, 1, 0, 5, 0, 4, 4, 4, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,", 32, 25, ks0);

	maps.push_back(m);
}


Server::~Server()
{
}


void Server::run()
{
	sf::TcpSocket * nextClient = nullptr;
	std::cout << "SERVER STARTED ..." << std::endl;
	try {
		while (1) {
			// Handle newcoming clients
			if (nextClient == nullptr) {
				nextClient = new sf::TcpSocket();
				nextClient->setBlocking(false);
			}
			if (listener.accept(*nextClient) == sf::Socket::Done) {
				clients.insert(std::make_pair(nextClient, ""));
				std::cout << "Insertado usuario " << nextClient->getRemotePort() << std::endl;
				nextClient = nullptr;
			}
			handleMessages();
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

void fixBufferTCP(char buffer[], std::string& str) {
	str = buffer;
	str = str.substr(0, str.find_last_of("}") + 1);
}

void Server::handleMessages()
{
	char buffer[512];
	std::size_t received;
	std::string buff_str;
	for (Clients_Sockets::iterator it = clients.begin(); it != clients.end();) {
		try {
			for (int i = 0; i < 512; i++) {
				buffer[i] = 0;
			}
			sf::Socket::Status status = (*it).first->receive(buffer, MAXBUFF, received);
			bool exit = false;
			switch (status) {
			case sf::Socket::Done: {
				fixBufferTCP(buffer, buff_str);
				//std::cout << buff_str << std::endl;
				Jzon::Node node = parser.parseString(buff_str);
				if (!node.isValid()) {
					std::cout << "Error " << buff_str << std::endl;
					Jzon::Node n = Jzon::object();
					n.get("Action").set("resend");
					Jzon::Writer w;
					w.writeString(n, buff_str);
					std::string err = "resend\n";
					(*it).first->send(err.c_str(), err.length());
				}
				else {
					std::string action = node.get("Action").toString();
					std::cout << "ACTION : " << action << std::endl;
					if (action == "initWName") {
						float posX = 320;
						float posY = 320;
						int id = (*it).first->getRemotePort();
						ObjectUser *ou = new ObjectUser(id, posX, posY);
						std::string username = node.get("Name").toString();
						clients[(*it).first] = username;
						Jzon::Node root = Jzon::Node(Jzon::Node::T_OBJECT);
						root.add("Action", "sendMap");
						root.add("Id", ou->getId());
						Jzon::Node map0 = Jzon::Node(Jzon::Node::T_OBJECT);
						Map* m = maps[ou->getMap()];
						map0.add("Id", m->getId());
						map0.add("MapFields", m->getMapFields());
						map0.add("Width", m->getWith());
						map0.add("Height", m->getHeight());


						Jzon::Node objects_ = Jzon::array();
						for each (KeyObject* ko in m->getKeyObjects())
						{
							Jzon::Node oo = Jzon::object();
							oo.add("Id", ko->getId());
							oo.add("Color", ko->getColor());
							oo.add("PosX", ko->getPosX());
							oo.add("PosY", ko->getPosY());
							objects_.add(oo);
							std::cout << objects_.getCount() << std::endl;
						}
						std::cout << objects_.getCount() << std::endl;

						map0.add("KeyObjects", objects_);

						root.add("Map", map0);
						root.add("X", posX);
						root.add("Y", posX);

						Jzon::Node users_ = Jzon::array();

						for each (std::pair<int, ObjectUser*> n in users)
						{
							Jzon::Node uu = Jzon::object();
							uu.add("Id", n.second->getId());
							uu.add("PosX", n.second->getPosX());
							uu.add("PosY", n.second->getPosY());
							users_.add(uu);
						}
						users.insert(std::pair<int, ObjectUser*>(ou->getId(), ou));

						root.add("Users", users_);
						Jzon::Writer w;
						std::string str;
						w.writeString(root, str);
						str += "\n";
						(*it).first->send(str.c_str(), str.length());


						if (isGame) {
							char* retOthers = new char[MINBUFF];
							sprintf(retOthers, "{\"Action\":\"new\",\"Id\":%d,\"PosX\":%f,\"PosY\":%f}", ou->getId(), ou->getPosX(), ou->getPosY());

							broadcast(retOthers, (*it).first);
						}
					}
					else if (action == "move") {
						int id = (*it).first->getRemotePort();
						ObjectUser *ou = users[id];
						ou->setPosition(node.get("Pos").get("X").toFloat(), node.get("Pos").get("Y").toFloat());	// El parseo de Float va correcto!
						// Al ser punteros, no hace falta "setear" el ObjectUser guardado en el mapa anteriormente.

						if (isGame) {
							broadcast(buff_str, (*it).first);
						}
						else {
							(*it).first->send(buffer, MAXBUFF);
						}
					}
					else  if (action == "position") {
						char* ret = new char[MINBUFF];
						ObjectUser *ou = users[(*it).first->getRemotePort()];
						sprintf(ret, "{\"Action\":\"position\",\"Id\":%d,\"PosX\":%f,\"PosY\":%f}", ou->getId(), ou->getPosX(), ou->getPosY());
						(*it).first->send(ret, MINBUFF);
						delete(ret);
					}
					else if (action == "initFight") {

					}
					else if (action == "sendAckInitFight") {

					}
					else if (action == "okInitFight") {
						int id_battle = node.get("Id_battle").toInt();

						FightStatus* fs = battles[id_battle];
						fs->addPlayer(); // El mutex se encuentra aqu�!
						if (fs->getPlayers() == 2) {
							fs->setState(FightStatus::Status::Fight);

							//sf::Thread thread(&Server::battleSchedule, &fs);
							//thread.launch();
						}
					}


					else if (action == "fight") {
					}
					else if (action == "finishBattle") {
					}
					else if (action == "getObj") {
						mutexObjects.lock();
						int id_obj = node.get("Id_obj").toInt();
						auto ko = maps[0]->removeKey(id_obj);
						char* ret = new char[MINBUFF];
						int ok = 0;
						if (ko != nullptr) {
							ok = 1;
						}
						sprintf(ret, "{\"Action\":\"getObjFromServer\",\"Id\":%d,\"Ok\":%d}", id_obj, ok);
						(*it).first->send(ret, MINBUFF);
						delete(ret);
						mutexObjects.unlock();
						if (ok == 1) {
							broadcast(buff_str, (*it).first);
						}
					}
					else if (action == "freeObj") {
						mutexObjects.lock();
						node = node.get("Obj");
						int id_obj = node.get("Id_obj").toInt();
						float px = node.get("PosX").toFloat();
						float py = node.get("PosY").toFloat();
						bool okFree = maps[0]->addKey(id_obj, px, py);
						char* ret = new char[MINBUFF];
						int ok = 0;
						if (okFree) {
							ok = 1;
						}
						sprintf(ret, "{\"Action\":\"liberateObj\",\"Id\":%d,\"Ok\":%d}", id_obj, ok);
						(*it).first->send(ret, MINBUFF);
						delete(ret);
						mutexObjects.unlock();
						if (ok == 1) {
							node.get("Action").set("addObj");
							Jzon::Writer w;
							w.writeString(node, buff_str);
							broadcast(buff_str, (*it).first);
						}
					}
					else if (action == "exit") {
						std::cout << (*it).second << " has been disconnected\n";
						int id = (*it).first->getRemotePort();

						if (isGame) {
							node.add("Id", id);
						}
						else {
							node.add("Id", "Me");
						}
						Jzon::Writer w;
						w.writeString(node, buff_str);
						mutex.lock();
						delete users[id];
						users.erase(id);
						if (!isGame) {
							buff_str += "\n";
							(*it).first->send(buff_str.c_str(), MINBUFF);
						}
						it = clients.erase(it);
						//delete it->first;
						mutex.unlock();

						if (isGame) {
							broadcast(buff_str, (*it).first);
						}

						exit = true;
					}
					if (!exit) { ++it; }
				}
				break;
			}
			case sf::Socket::Disconnected: {
				std::cout << (*it).second << " has been disconnected\n";
				int id = (*it).first->getRemotePort();
				Jzon::Node node = Jzon::object();
				node.add("Action", "exit");

				if (isGame) {
					node.add("Id", id);
				}
				else {
					node.add("Id", "me");
				}
				Jzon::Writer w;
				w.writeString(node, buff_str);

				if (isGame) {
					broadcast(buff_str, (*it).first);
				}
				else {
					(*it).first->send(buff_str.c_str(), MINBUFF);
				}
				mutex.lock();
				delete users[id];
				users.erase(id);
				it = clients.erase(it);
				//delete it->first;
				mutex.unlock();
				break;
			}
			default:
				++it;
			}
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void Server::broadcast(std::string str, sf::TcpSocket* c)
{
	sf::Thread thread([&]()
	{
		std::for_each(clients.begin(), clients.end(), [&](std::pair<sf::TcpSocket*, std::string> client){
			if (client.first != c) {
				client.first->send(str.c_str(), str.length());
			}
		});
	});
	thread.launch();
}
