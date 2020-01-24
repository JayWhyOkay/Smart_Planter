# Generated by Django 2.1.1 on 2019-11-17 09:10

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('webapp', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='Account',
            fields=[
                ('username', models.CharField(max_length=45, primary_key=True, serialize=False)),
                ('password', models.CharField(blank=True, max_length=45, null=True)),
            ],
            options={
                'db_table': 'account',
                'managed': False,
            },
        ),
    ]
