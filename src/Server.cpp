/*
 * Server.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Server.h"

using namespace std;

Server::Server(cppcms::service &srv) :
		cppcms::application(srv) {
	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	dispatcher().assign("/home", &Server::home, this);

	dispatcher().assign("/problem", &Server::problem, this);

	dispatcher().assign("/solution", &Server::solution, this);

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::welcome() {
	response().out() << "Welcome";
}

void Server::home() {
	response().out() << "Home";
}

void Server::problem() {
	response().out() << "Problem";
}

void Server::solution() {
	response().out() << "Solution";
}

void Server::main(string url) {
}

int main(int argc, char ** argv) {
	try {
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(cppcms::applications_factory<Server>());

		cerr << "Server started!" << endl;
		srv.run();
	} catch (std::exception const &e) {
		cerr << e.what() << std::endl;
	}
}
