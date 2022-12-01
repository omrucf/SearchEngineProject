# SearchEngineProject

                        This is a search engine project done by Omar Yossuf for the CSCE 2203 course instructed by DR. Nada Gaballah                        

First pseudo code: 

        Search:
                search is separated to three different functions that all take a 
                string as their parameter and return a vector of pointers of type
                website (class). Also, all transform all the keywords to 
                uppercase so that the search is not case sensitive. However, ANDs 
                and ORs are case sesitive as they are commands and of course what 
                is between "" is also case sensitive.

                First ANDSearch type:
                    initialize a boolian flag to be true.
                    if a website does not contain at least one keyword from the 
                    input, let the flag be false and end the loop.
                    after the loop, if the flag is still true, add that website's 
                    pointer to the vector of pointers that should be returned at 
                    the end of the function.

                Second ORSerch type:
                    initialize a boolian flag to be false. 
                    if a website contains at least one keyword from the 
                    input, let the flag be true and end the loop.
                    after the loop, if the flag is still true, add that website's 
                    pointer to the vector of pointers that should be returned at 
                    the end of the function.