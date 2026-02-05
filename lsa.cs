using System;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public void ShowInfo()
    {
        Console.WriteLine($"Имя: {Name}, Возраст: {Age}");
    }

    public void SayHello()
    {
        Console.WriteLine($"Привет, меня зовут {Name}!");
    }
}

public class Student : Person
{
    public string University { get; set; }

    public Student(string name, int age, string university) : base(name, age)
    {
        University = university;
    }

    public void Study()
    {
        Console.WriteLine($"{Name} учится в {University}.");
    }
}

public class Teacher : Person
{
    public string Subject { get; set; }

    public Teacher(string name, int age, string subject) : base(name, age)
    {
        Subject = subject;
    }

    public void Teach()
    {
        Console.WriteLine($"{Name} преподаёт {Subject}.");
    }
}

public class Doctor : Person
{
    public string Specialization { get; set; }

    public Doctor(string name, int age, string specialization) : base(name, age)
    {
        Specialization = specialization;
    }

    public void Treat()
    {
        Console.WriteLine($"{Name} лечит пациентов как {Specialization}.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Student student = new Student("Илья", 20, "ПТУ");
        Teacher teacher = new Teacher("Максим", 21, "Физики");
        Doctor doctor = new Doctor("Вадим", 23, "Хирург");

        student.ShowInfo();
        teacher.ShowInfo();
        doctor.ShowInfo();

        student.Study();
        teacher.Teach();
        doctor.Treat();

        student.SayHello();
        teacher.SayHello();
        doctor.SayHello();
    }
}
