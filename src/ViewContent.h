#ifndef VIEWCONTENT_H_
#define VIEWCONTENT_H_

// Includes
#include "Clarification.h"
#include "Problem.h"
#include "Solution.h"
#include <cppcms/form.h>
#include <cppcms/view.h>
#include <list>
#include <string>

// Type definitions
typedef Problem *ProblemPointer;
typedef Solution *SolutionPointer;
typedef std::list<Problem *> *ProblemList;
typedef std::list<Solution *> *SolutionList;
typedef std::list<Clarification *> *ClarificationList;


namespace ViewContent {

struct TemplateContent: public cppcms::base_content {
	std::string page_title;
	bool user_logged = 0;
	std::string user_name;
};

struct IdeasContent: TemplateContent {
};

struct IndexContent: TemplateContent {
};

struct ProblemContent: TemplateContent {
	Problem *problem;
	Solution *accepted_solution;
	std::list<Solution *> *solutions;
	std::list<Clarification *> *clarifications;
};

struct ProblemsContent: TemplateContent {
	ProblemList problems;
};

struct SignInFormInfo: public cppcms::form {
	cppcms::widgets::text user_name;
	cppcms::widgets::password password;
	cppcms::widgets::submit submit;

	SignInFormInfo() {
		user_name.message("User name");
		password.message("Password");
		submit.value("Sign in");

		add(user_name);
		add(password);
		add(submit);

		// Restrictions
		user_name.limits(1, 31);
		password.non_empty();
	}
};

struct SignInContent: TemplateContent {
	SignInFormInfo form_info;
};

struct SolutionContent: TemplateContent {
	Solution *solution;
	std::list<Clarification *> *clarifications;
};
}

#endif /* VIEWCONTENT_H_ */
