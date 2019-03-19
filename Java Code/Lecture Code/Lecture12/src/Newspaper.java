/*Observer Pattern. We create a subject(newspaper) and an Observer(reader). The subject stores the list of
observers that is observing it. Once it makes an update then it will notify all the relevant observers.
 Below is an instance of a pull observer where the observer must go to the subject whereas a push observer
 pushes the state directly to the observer. Pull = the observer may be out of sync but only get the state it
 requires. Push = the observer may get more information than needed but gets it immediately*/


import java.util.*;
class Newspaper {
    private String name;
    private List<String> articles;
    private Set<Reader> readers;
    Newspaper(String name) {
        articles = new ArrayList<String>();
        readers = new HashSet<Reader>();
        this.name = name;
    }
    void addArticle(String article) {
        articles.add(article);
        announce();
    }
    String getArticle(int issue) {
        String article = name + " : ";
        if (issue > 0 && issue <= articles.size())
            return (article + articles.get(issue - 1));
        else
            return (article + " : Bad issue number!");
    }
    int getIssue() {
        return (articles.size());
    }

    void register(Reader reader) {
        readers.add(reader);
    }
    void unregister(Reader reader) {
        readers.remove(reader);
    }
    void announce() {
        for (Reader reader : readers) {
            reader.readArticle(this);
        }
    }
}
