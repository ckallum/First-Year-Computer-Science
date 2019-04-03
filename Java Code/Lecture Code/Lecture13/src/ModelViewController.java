public class ModelViewController {
}

/* Model view controller trie to separate the logic/model
 which dictates the state of the app and the
GUI(display). This allow's code to be managed easier.

We implement Rendering Logic and Event Handling Logic to allow
interactions between the two.

Model: = Domain(handles logic and rules)
View: = Rendering Logic + Display(User interface)
Controller: = Event Handling Logic(keystrokes user interactions etc.)

Pattern in MVC:
    - Observer Pattern: view updates when model changes
    - Composite Pattern: components in view in GUI
    - Strategy Pattern: Event Handling Logic decides event
                        depending on the input of view.

   Problems:
    - Event handling will directly be rendered into GUI
      eg. typing
    - Domain will directly impact event handling through
      input validation.

   FIX:
   MODEL VIEW PRESENTER

 */