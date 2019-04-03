public class CompositePattern {
}
/* Hierarchical pattern/ tree structure. eg a GUI windows
which contains multiple objects in it, they may have the same
attributes eg. text box.
Let's compositions of objects to be treated uniformly i.e. it
allows child objects of the component to implement the same operation

Example: Component = Orchestra
                     -Made up of different sections
                     -Each section is made up of instruments
                     -For an orchestra to play()
                      so must all it's child composite parts
                     -Effectively play() called from Orchestra
                     creates a cascade of play () events
 */
