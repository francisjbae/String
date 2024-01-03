#include "string.h"
#include <cstring>
namespace String 
{
	string::string()
	{
		len = 0;
		buffer = nullptr;
	}

	string::string(const char s[])
	{
		len = strlen(s);
		if (len > 0)
		{
			buffer = new char[len];
			for (int i = 0; i < len; i++)
			{
				buffer[i] = s[i];
			}
		}
		else
		{
			buffer = nullptr;
		}
	}

	string::string(const string& other)
	{
		len = other.len;
		if (len > 0)
		{
			buffer = new char[len];
			for (int i = 0; i < len; i++)
			{
				buffer[i] = other.buffer[i];
			}
		}
		else
		{
			buffer = nullptr;
		}
	}

	string& string::operator=(const string& other)
	{
		if (this != &other)
		{
			delete[] buffer;
			len = other.len;
			if (len > 0)
			{
				buffer = new char[len];
				for (int i = 0; i < len; i++)
				{
					buffer[i] = other.buffer[i];
				}
			}
			else
			{
				buffer = nullptr;
			}
		}
		return *this;
	}

	string::~string()
	{
		delete[] buffer;
	}

	int string::length() const
	{
		return len;
	}

	int string::size() const
	{
		return len;
	}

	char& string::operator[](int i)
	{
		return buffer[i];
	}

	const char& string::operator[](int i) const
	{
		return buffer[i];
	}

	string string::operator+(const string& other) const
	{
		string result;
		result.len = len + other.len;
		result.buffer = new char[result.len];
		for (int i = 0; i < len; i++)
		{
			result.buffer[i] = buffer[i];
		}
		for (int i = 0; i < other.len; i++)
		{
			result.buffer[len + i] = other.buffer[i];
		}
		return result;
	}

	string string::operator+(const char& ch) const
	{
		string result;
		result.len = len + 1;
		result.buffer = new char[result.len];
		for (int i = 0; i < len; i++)
		{
			result.buffer[i] = buffer[i];
		}
		result.buffer[len] = ch;
		
		return result;
	}

	bool string::operator==(const string& other) const
	{
		if (len != other.len) { return false; }
		for (int i = 0; i < len; i++)
		{
			if (buffer[i] != other.buffer[i]) { return false; }
		}
		return true;
	}

	int string::find(const char* s, int pos) const
	{
		int len2 = strlen(s);
		for (int i = pos; buffer[i] != '\0'; i++) 
		{
			if (buffer[i] == s[0]) {
				int j;
				for (j = 1; s[j] != '\0'; j++) 
				{
					if (buffer[i + j] != s[j]) 
					{
						break;
					}
				}
				if (s[j] == '\0') {
					return i;
				}
			}
		}
		return -1;
	}

	void string::print(ostream& out) const
	{
		for (int i = 0; i < len; i++)
		{
			out << buffer[i];
		}
	}

	ostream& operator<<(ostream& out, const string& str)
	{
		str.print(out);
		return out;
	}

	istream& operator>>(istream& in, string& str)
	{
		str = string();
		char c;
		while (in.get(c))
		{
			if (c == ' ' || c == '\n' || c == '\t')
			{
				break;
			}
			str = str + c;
		}
		return in;
	}

	bool operator!=(const string& s, const string& t)
	{
		return !(s == t);
	}

	bool operator>(const string& lhs, const string& rhs)
	{
		int i = 0;
		while (i < lhs.length() && i < rhs.length())
		{
			if (lhs[i] > rhs[i])
			{
				return true;
			}
			else if (lhs[i] < rhs[i])
			{
				return false;
			}
			i++;
		}
		return lhs.length() > rhs.length();
	}

}

