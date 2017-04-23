//#include <iostream>
//#include <string>
//#include <memory>
//using namespace std;
//
//class base
//{
//public:
//	virtual void show() = 0;
//};
//
//class factory
//{
//public:
//	virtual unique_ptr<base> make_in_factory(string s, string t) = 0;
//};
//
//class sample :public base
//{
//	string name;
//public:
//	sample(string s) :name(s) {}
//	void show() { cout << "name = " << name << endl; }
//};
//
//class pr :public factory
//{
//public:
//	unique_ptr<base> make_in_factory(string s, string t)override {
//		if (s == "sample") {
//			return make_unique<sample>(t);
//		}
//		else {
//			cout << "error!";
//			return nullptr;
//		}
//	}
//};
//
//void delsample(sample* s)
//{
//	cout << "ptr deleted!";
//	delete s;
//}
//
//int main()
//{
//	unique_ptr<sample> uni_ptr = std::make_unique<sample>("hallo");
//	unique_ptr<sample> uni_ptr1 = std::move(uni_ptr);
//
//	uni_ptr1->show();
//
//	return 0;
//}

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
	char* BackSlash;
	char CurrentDirPath[_MAX_PATH];
	BackSlash = strrchr(argv[0], '\\');
	strncpy_s(CurrentDirPath, argv[0], BackSlash - argv[0]);

	if (argc < 1){
		std::cout << "directory not found";
	}
	else {
		std::string d, s;
		d += argv[1];

		if (d[1] == ':') {
			s += d[0];
			s += ": ";
		}
		s += "cd ";
		s += argv[1];
		s += " & dir *.txt /-C > ";
		s += CurrentDirPath;
		s += "\\txt.tmp";

		system(s.c_str());

		std::ifstream reading_file("txt.tmp");
		std::string reading_line_buffer;

		reading_file.seekg(75, std::ios_base::end); //1+32+17+18=68 +7=75

	}

	return 0;
}