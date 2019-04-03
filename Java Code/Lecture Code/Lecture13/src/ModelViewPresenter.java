public class ModelViewPresenter {
}

/*A more divided implemention of MVC between Model and View
    - Combines rendering logic and event handling into a Presenter
           -Seperates model and view into seperate boxes

    Patterns:
    - Observer: When the model changes, the Presenter will update
                accordingly.
                When the display changes, the presenter will update
                it's event and render them(typing).
    - Composite: Display is still a GUI with multiple components

 */
