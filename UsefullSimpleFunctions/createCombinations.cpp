template<typename T>
std::vector<std::vector<T>> combinationOfVector(std::vector<T> vector,int nOfElem)
{
   std::vector<int> boleamRepresentationOfCombinations(vector.size(),0);
   for(auto it = boleamRepresentationOfCombinations.end()-nOfElem;it!=boleamRepresentationOfCombinations.end();it++)
   {
       *it=1;
   }
    //   std::vector<std::vector<T>> toReturn(static_cast<int>(boost::math::binomial_coefficient<double>(vector.size(), nOfElem)));
    //doenst work properly :c
    //need optymalization here
    std::vector<std::vector<T>> toReturn;

   if(!std::is_sorted(boleamRepresentationOfCombinations.begin(),boleamRepresentationOfCombinations.end()))
       std::sort(boleamRepresentationOfCombinations.begin(),boleamRepresentationOfCombinations.end());
   do{
       std::vector<T> combination;
       combination.reserve(nOfElem);
       for(int i=0;i<boleamRepresentationOfCombinations.size();i++)
       {
            if(boleamRepresentationOfCombinations[i])
                combination.push_back(vector[i]);
       }
       toReturn.push_back(std::move(combination));
   }while(std::next_permutation(boleamRepresentationOfCombinations.begin(),boleamRepresentationOfCombinations.end()));
   return toReturn;
}


/*
function is returning vector of vectors
where is all possible n elem combinations of vector<T>
needed is optymalization in line 12
needed is exception handling: when u passing smaller vect.size than nofElem ect.
*/