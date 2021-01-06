using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simple_OOP_Game
{
    class Player
    {
        protected string name;
        protected double health, attack;

        public string Name
        {
            set; get;
        }

        public double Health
        {
            set; get;
        }

        public double Attack
        {
            set; get;
        }

        public Player()
        {
            name = "a"; health = 0; attack = 0;
        }

        public Player(string aName, double aHealth, double aAttack)
        {
            name = aName; health = aHealth; attack = aAttack;
        }

        public override string ToString()
        {
            return name + " has " + health + " health and " + attack + " attack";
        }
    }
}
