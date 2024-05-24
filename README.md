# Document-Query-Solver
Software to solve queries from any corpus.
<h2>Pattern Matching</h2>
The idea of this project germinates with pattern matching. Algorithms like KMP are used to look for patterns in any large text in O(n) time where n is the size of the whole text. But when we implement query answering, we can optimise heavily. Instead of looking for patterns, we now have to look for each individual word in the query and then check for its appearences in the text. We can thus implement a modified Trie which stores the locations of the words inserted into the text. Thus the time complexity reduces from O(n) to O(m) where m is the size of a word in the question and this is bounded as the longest english word is only 45 letters long. This means our pattern search operation is O(1).
<h2>Paragraph Ranking</h2>
To know the answer to our question, we must first find out which paragraphs are most relevant to the query. To rank the paragraphs scores are assigned to each paragraphs and top K paragraphs are returned where K is some number decided by the user. Note that k denotes the maximum number of paragraphs that will be returned, the actual number returned may be less than K as it may happen that less that K paras are only relevant. To score the paras, the formula used in the project is summation of the scores of the words matching from the question. The scores of the words are inverse square of the number of occurences of that word in whole text.
<h2>Software Requirements and Running the code</h2>
<ul>
  <li>Make sure python is installed in your system.</li>
  <li>Install openai on your system by <strong><em>"pip install openai"</em></strong></li>
  <li>Now place all the books as text files in the same directory and name them serially. For example, say you want an answer from Shakespeare's work, you may name the books <em>Shakespeare-1</em>, <em>Shakespeare-2</em>, <em>Shakespeare-3</em> and so on.</li>
  <li>generate an execuatable by running the command <strong><em>g++ tester.cpp dict.cpp Node.cpp qna_tool.cpp search.cpp -o test</em></strong></li>
  <li>Run the execuatble by <strong><em>./test</em></strong> and then follow the instructions printed on the console.</li>
  <li>After the paragraphs are returned, run the python file by using the following command: <strong><em>python3 api_call.py API_KEY paragraph_0.txt paragraph_1.txt paragraph_2.txt query.txt</em></strong> Here top 3 paragraphs are chosen, you can choose more by simply writing more paragraph_n.txt in the command. Replace API_KEY with your openai api key.</li>
  <li>Your answer must display now.</li>
</ul>
