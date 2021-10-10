#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool is_valid_regex_string(const std::string &rgx_str)
{
  bool bResult = true;
  try
  {
    std::regex tmp(rgx_str);
  }
  catch (const std::regex_error &e)
  {
    (e);
    bResult = false;
  }
  return bResult;
}

int main()
{

  std::string current_word_input = "Default starting string";
  std::string current_regex_input = "[a-zA-Z\\s]+";
  while (true)
  {
    std::string word_input;
    std::string regex_input;
    cout << "Enter the string for matching [" << current_word_input << "]: ";
    std::getline(cin, word_input);
    if (word_input == "q")
    {
      break;
    }
    if (word_input == "")
      word_input = current_word_input;
    cout << "Enter the regex rule [" << current_regex_input <<"]: ";
    std::getline(cin, regex_input);
    if (regex_input=="")
      regex_input = current_word_input;

    if (is_valid_regex_string(regex_input))
    {
      std::regex pattern(regex_input);

      if (regex_match(word_input, pattern))
      {
        cout << "Matching!" << endl;
      }
      else
      {
        cout << "Not matching!" << endl;
      }
      current_word_input = word_input;
      current_regex_input = regex_input;
    }
    else
    {
      cout << "ERROR! Wrong regex format" << endl;
    }
  }
  return 0;
}
