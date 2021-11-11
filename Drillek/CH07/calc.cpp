#include "./std_lib_facilities.h"

struct Token {
		// All Tokens have a 'kind', value and name are optional
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
		Token(char ch, string s) :kind(ch), name(s) { }
};

class Token_stream {
	bool full;
	Token buffer;

	public:
	Token_stream() :full(0), buffer(0) { }
	Token get();
	void unget(Token t) { buffer=t; full=true; }
	void ignore(char);
};

const char quit = 'Q';
const char let = '#';
const char name = 'a';
const char number = '8';
const char print = ';';
const char square_root = '?';
const char exponent = '^';

Token Token_stream::get() {
	if (full) { full=false; return buffer; }

	char ch;
	cin >> ch;
	switch (ch) {
		case quit:
		case square_root:
		case exponent:
		case let:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': {	
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == "exit") return Token(quit);
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) {
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> var_names;	

double get_value(string s) {
	for (int i = 0; i<var_names.size(); ++i) {
		if (var_names[i].name == s) return var_names[i].value;
	}
	error("get: undefined name ",s);
}

void set_value(string s, double d) {
	for (int i = 0; i<var_names.size(); ++i) {
		if (var_names[i].name == s) {
			var_names[i].value = d;
			return;
		}
	}
	error("set: undefined name ",s);
}

bool is_declared(string s) {
	for (int i = 0; i<var_names.size(); ++i) {
		if (var_names[i].name == s) return true;
	}
	return false;
}

Token_stream ts;

double expression();

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
		case square_root: {
			double d = primary();
			if (d < 0) error("Can't sqrt() Imaginary #");
			return sqrt(d);
		}
	default:
		error("primary expected");
	}
}

double pow(double base, double exp)
{
	int x = narrow_cast<int>(exp);

	double n = 1;
	double b;

	if (exp < 0) {
		b = 1 / base;
		x *= -1;
	} else {
		b = base;
	}

	for (int i = 0; i < x; ++i) {
		n *= b;
	}

	return n;
}

double secondary() {
  double left = primary();
  while(true) {
    Token t = ts.get();
    switch(t.kind) {
      case '^':
        return pow(left, primary());
      default:
        ts.unget(t);
        return left;
    }
  }
}

double term() {
	double left = secondary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= secondary();
			break;
		case '/': {
      double d = secondary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration() {
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string name = t.name;           // name already defined in outer scope

	if (is_declared(name)) error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);

	double d = expression();
	var_names.push_back(Variable(name,d));
	return d;
}

double statement() {
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess() {
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() {
  var_names.push_back(Variable("pi", 3.14159));
  var_names.push_back(Variable("e", 2.718281828));
  var_names.push_back(Variable("k", 1000));

	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
	try {
		calculate();
		return 0;
	} catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	} catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
