#pragma once
#include <SFML/System/Mutex.hpp>
class FightStatus
{
public:
	typedef enum Status { None, Init, NeedACK, OKInit, Fight, FinalFight } Status;
private:
	int id_battle;
	int id_emisor;
	int id_receiver;
	Status state;
	int semaphore;
	bool finish;
	sf::Mutex m;
public:
	FightStatus(int id_battle, int id_emisor, int id_receiver) {
		this->id_battle = id_battle;
		this->id_emisor = id_emisor;
		this->id_receiver = id_receiver;
		this->state = Status::None;
		this->finish = false;
		this->semaphore = 0;
	}
	Status getState() {
		return state;
	}
	int getPlayers() {
		m.lock();
		int c = this->semaphore;
		m.unlock();
		return c;
	}
	void setState(Status state) {
		if (state == Status::FinalFight) {
			this->finish = true;
		}
		this->state = state;
	}
	int getId_battle() {
		return id_battle;
	}
	int getId_emisor() {
		return id_emisor;
	}
	int getId_receiver() {
		return id_receiver;
	}
	bool isFinish() {
		return finish;
	}

	~FightStatus();

	void addPlayer() {
		m.lock();
		semaphore++;
		m.unlock();
	}
};

