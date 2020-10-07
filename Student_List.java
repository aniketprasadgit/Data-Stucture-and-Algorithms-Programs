// Format Student data based on CGPA, ID and Name using ArrayList and others

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.*;
class Student{
        private int id;
        private String name;
        private double cgpa;
        public Student(String name, double cgpa,int id) {
            super();
            this.id = id;
            this.name = name;
            this.cgpa = cgpa;
        }
        public int getId() {
            return id;
        }
        public void setId(int id) {
            this.id = id;
        }
        @Override
        public String toString() {
            return "Student [id=" + id + ", name=" + name + ", cgpa=" + cgpa
                    + "]";
        }
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
        public double getCgpa() {
            return cgpa;
        }
        public void setCgpa(double cgpa) {
            this.cgpa = cgpa;
        }
    }
    class Priorities{
    List<Student> ls=new ArrayList<Student>();

    List<Student> getStudents(List<String> events){
    for(String l:events){
        if(l.startsWith("ENTER")){
            String[] s=l.split(" ");
            Student snew=new Student(s[1],Double.parseDouble(s[2]),Integer.parseInt(s[3]));
            ls.add(snew);
            if(ls.size()>1){
                Collections.sort(ls, new Comparator<Student>() {
                    @Override
                    public int compare(Student s1, Student s2) {
                        if(s1.getCgpa()==s2.getCgpa()){
                            if(s1.getName().compareTo(s2.getName())==0){
                                if(s1.getId()>s2.getId()) return 1;
                                if(s1.getId()<s2.getId()) return -1;
                                return 0;
                            }else{
                                return s1.getName().compareTo(s2.getName());
                            }
                        }
                        else{
                            if(s1.getCgpa()>s2.getCgpa()) return -1;
                            else return 1;
                        }
                            
                    }
                });
        }
    }else{
        if(ls.isEmpty()) return ls;
        else ls.remove(0);        
    }
}
        return ls;
    }
}

public class Solution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();
    
    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());    
        List<String> events = new ArrayList<>();
        
        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }
        
        List<Student> students = priorities.getStudents(events);
        
        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}
