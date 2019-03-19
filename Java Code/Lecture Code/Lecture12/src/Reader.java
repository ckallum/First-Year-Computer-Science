import java.util.*;
class Reader {
    String name;
    List<Newspaper> newspapers;
    Reader(String name) {
        this.name = name;
        newspapers = new ArrayList<Newspaper>();
    }
    void readArticle(Newspaper newspaper) {
        int issue = newspaper.getIssue();
        String article = newspaper.getArticle(issue);
        System.out.println(name + " reads: " + article);
    }
    void readArticles() {
        for (Newspaper newspaper : newspapers) {
            readArticle(newspaper);
        }
    }
    void subscribe(Newspaper newspaper) {
        newspapers.add(newspaper);
        newspaper.register(this);
    }
} 