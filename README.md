# CS210-Airgead
8-1 Journal Submission

Question Response:
• _Summarize the project and what problem it was solving._
  This project was set up to help us use the OOP principles that we learned in the beginning half of the class and how to create proper pseudocode/flowcharts to support our code. This consisted of us creating a program that calculated compounding interest in a user's investment account. We had to set up a main file that held as little code as possible and have most of the computations occur in our class files.
  
• _What did you do particularly well?_
  I think I handled exceptions, errors, and user deviation particularly well in my program. I always strive to make sure that the user experience is streamlined and has minimal potential for crashing or input that could cause issues. This makes sure that everything runs smoothly.
  
• _Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?_
  I personally think that I overexplained things in my comments, didn't release my variables/objects, and didn't do my "press any key to continue" correctly. I usually try and give general overviews of what I'm doing in a function, loop. method, etc. However, I think that I put too many comments in my code in this project explaining things that didn't need an explaination. This is very noticeable in main. I also didn't release my varaibles and objects at the end of my code. This isn't a huge issue in this program since it terminates relatively quickly. It can be a security or efficiency issue on bigger programs because you can wind up with unneeded memory being used that can cause a leak or the program to begin running slow.
  
• _Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?_
  I found the "InterestAccount.display()" method most challenging. The idea was simple, yet trying to overcome the limitations of the iomanip libray's methods when trying to format the display was a challenge for me. Specifically dealing with setw only working on the next output item. I overcame this by turning to our fellow programmer on sites like stack overflow and the documentation of the methods in cout. I ended up finding out about the put_money method from the community and reading up about it in the documentation, which was exactly what I was looking for to help me properly format my table. I will always keep the community and documentation in my backpocket as there is almost always someone that you can learn from or point you in the direction that you need.
  
• _What skills from this project will be particularly transferable to other projects or course work?_
  The ability to properly utilize OOP principles, memory/object management, and input/error management is huge in the programming world. I can garentee that I will be using them throughout my career in Computer Science.
  
• _How did you make this program maintainable, readable, and adaptable?_
  I made sure to add comments, proper naming conventions, and used OOP principles throughout the program. Specifically, I had comments throughout my code and named everything properly to make sure that future programmers could understand what I was trying to accomplish. I extensively used the principles of encapsilation and abstraction in my class. I had all my local variables privated and seperated reusable code segements into specific, related methods. I also ensured that the InvestorAccount class only focused on the elements important to it.
