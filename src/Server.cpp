/*
 * Server.cpp
 *
 *  Created on: 02/01/2013
 *      Author: nico
 */

#include "Server.h"
#include "main_screen_content.h"
#include <string>
using namespace std;

Server::Server(cppcms::service &srv) :
		cppcms::application(srv) {
	db = new DatabaseInterface();

	dispatcher().assign("", &Server::welcome, this);
	mapper().assign("");

	dispatcher().assign("/problemsHome", &Server::problems_home, this);
	mapper().assign("problemsHome", "/problemsHome");

	dispatcher().assign("/ideasHome", &Server::ideas_home, this);
	mapper().assign("ideasHome", "/ideasHome");

	dispatcher().assign("/problem/(\\d+)", &Server::problem, this, 1);
	mapper().assign("problem", "/problem/{1}");

	dispatcher().assign("/solution/(\\d+)", &Server::solution, this, 1);
	mapper().assign("solution", "/solution/{1}");

	mapper().root("/pci");
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::welcome() {
	main_screen_content::content c;
	c.user_id = "Anonimo";
	render("welcome", c);
}

void Server::problems_home() {
	main_screen_content::problemsHome problems_home;

	problems_home.problems = db->searchProblemsRandom(10);

	render("problemsHome", problems_home);
}

void Server::ideas_home() {
	response().out() << "Ideas Home";
}

void Server::problem(string problem_id) {
	main_screen_content::problemInfo problem_info;

	Problem* problem = db->searchProblem(problem_id);
	problem_info.problem = problem;
	if (problem->is_solved) {
		problem_info.accepted_solution = db->searchSolution(
				problem->accepted_solution_id);
	}

	problem_info.solutions = db->searchSolutions(problem_id);

	problem_info.clarifications = db->searchClarifications(problem_id);

	render("problemInfo", problem_info);
}

void Server::solution(string solution_id) {
	main_screen_content::solutionInfo solution_info;

	solution_info.solution = db->searchSolution(solution_id);

	solution_info.clarifications = db->searchClarifications(solution_id);

	render("solutionInfo", solution_info);
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

