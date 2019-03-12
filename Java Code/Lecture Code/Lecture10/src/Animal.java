abstract class Animal implements Comparable<Animal> {
    public abstract int getWeight();
    public int compareTo(Animal that){
        return (this.getWeight() - that.getWeight());
    }
}

//Allows us to sort lists of animals through comparisons ie.
/*List<Animal> animals = new ArrayList<Animal>();
  animals.add(elephant);
  animals.add(ant);
  Collections.sort(animals);

  //SortedSet is a a collection that stores elements in natural ordering
  SortedSet<Animal> animals = new TreeSet<Animal>();
  animals.add(elephant);
  animals.add(ant);
  for(Animal animal : animals){
    //Set's are iterable. Comes out as sorted
  }
 */


