# Dealing with production line issues
As explained in the use cases of the project (available in Ressources), some issues might occur in the SLD module (actually we listed 2 : the element does not come out of the furnace and the element is not delivered well with the piston).

In order to detect and mitigate these issues, we added some variables and methods to the code, now the factory reacts as follows :

- if the element does not reach the detector after the furnace, then the conveyer belt automatically stops after some pulses.
- if the element does not reach its color detector after being pushed by the piston then an alarm is raised.

In both cases a notification is displayed on the dashboard.

For the first issue, the element is hidden in Unity so that it doesn't bring false information.

Dealing with issues is important. Indeed, even your code will probably work 99,99% of the time it is fundamental to gather as much information as you can on a potential issue, either provoked by human beings or machines. This is part of the concept of digital twin.
