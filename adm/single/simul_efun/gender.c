// gender.c

string gender_self(string sex)
{
   return "��";
}

string gender_pronoun(string sex)
{
   switch (sex)
   {
   case "������":
   case "����":
   case "����":
      return "��";
   case "Ů��":
      return "��";
   case "����":
   case "����":
   default:
      return "��";
   }
}
