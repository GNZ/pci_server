#include <cppcms/view.h>  
#include <string>
using namespace std;

// Comentario de Fede

namespace main_screen_content{
	struct content: public cppcms::base_content{
		string user_id;
	};
}