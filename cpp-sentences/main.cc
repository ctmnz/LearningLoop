#include <iostream>
#include <string>
#include <unistd.h>
#include <term.h>

using namespace std;

void ClearScreen()
{
  if (!cur_term)
  {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
  }

  putp( tigetstr( "clear" ) );
}




int main()
{

  std::string current_sentence_written_input = "";
  std::string current_sentence_to_write_input = "";
  while (true)
  {
    std::string sentence_written_input;
    std::string sentence_to_write_input;
   
    cout << "Enter the sentence that you want to learn to write: ";
    std::getline(cin, sentence_written_input);
    if (sentence_written_input == "q")
    {
      break;
    }
    if (sentence_written_input == "")
      sentence_written_input = current_sentence_written_input;
  

    ClearScreen();

    cout << "Try to check your memory (write the sentence): ";
    std::getline(cin, sentence_to_write_input);

      if (sentence_to_write_input == sentence_written_input)
      {
        cout << "Matching!" << endl;
      }
      else
      {
        cout << "Not matching!" << endl;
        cout << "The original sentence: \t" << sentence_written_input << endl;
        cout << "Your sentence: \t\t" << sentence_to_write_input << endl;
      }

  current_sentence_written_input = sentence_written_input;
  current_sentence_to_write_input = sentence_to_write_input;
    
  }
  return 0;
}
