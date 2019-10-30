within Simulator.Files.Icons;

model Heater
  annotation(
    Diagram,
    Icon(graphics = {Ellipse(extent = {{-100, 100}, {100, -100}}, endAngle = 360), Line(points = {{-100, -100}, {100, 100}}, color = {255, 0, 0}), Line(origin = {90, 90}, points = {{-10, 10}, {10, 10}, {10, -10}}, color = {255, 0, 0}), Text(extent = {{-50, 50}, {50, -50}}, textString = "H", textStyle = {TextStyle.Bold}), Text(origin = {4, -132}, extent = {{-100, 24}, {102, -50}}, textString = "%name")}, coordinateSystem(initialScale = 0.1)));
end Heater;
